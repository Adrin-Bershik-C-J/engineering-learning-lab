# Smart Dashboard — Spring Boot Multithreading Demo

A Spring Boot project that demonstrates the performance difference between **synchronous** and **asynchronous (multithreaded)** service calls using `@Async` and `CompletableFuture`.

---

## Project Structure

```
multi-threading-springboot/
│
├── config/
│   └── AsyncConfig.java          # Thread pool configuration
│
├── controller/
│   └── DashboardController.java  # REST endpoints
│
├── service/
│   ├── DashboardService.java     # Orchestrates sync/async calls
│   ├── UserService.java
│   ├── PostService.java
│   ├── NotificationService.java
│   └── AnalyticsService.java
│
├── dto/
│   └── DashboardResponse.java    # Response model
│
└── MultiThreadingApplication.java
```

---

## How It Works

### Sync Flow — `/dashboard/sync`
Each service is called **sequentially**. Total time = sum of all delays.

```
UserService (1000ms) → PostService (1200ms) → NotificationService (800ms) → AnalyticsService (1500ms)
Total ≈ 4500ms
```

### Async Flow — `/dashboard/async`
All services are called **in parallel** using `@Async` + `CompletableFuture`. Total time = longest single delay.

```
UserService (1000ms) ─┐
PostService (1200ms) ──┤─→ allOf().join() → respond
NotificationService (800ms) ─┤
AnalyticsService (1500ms) ──┘
Total ≈ 1500ms
```

---

## Thread Pool Configuration

Defined in `AsyncConfig.java`:

| Property        | Value              |
|-----------------|--------------------|
| Core Pool Size  | 4                  |
| Max Pool Size   | 8                  |
| Queue Capacity  | 20                 |
| Thread Prefix   | `Dashboard-Thread-` |

---

## Endpoints

| Method | URL               | Description              |
|--------|-------------------|--------------------------|
| GET    | `/dashboard/sync` | Sequential service calls |
| GET    | `/dashboard/async`| Parallel service calls   |

---

## Running the App

```bash
./mvnw spring-boot:run
```

Then hit the endpoints:

```bash
curl http://localhost:8080/dashboard/sync
curl http://localhost:8080/dashboard/async
```

### Sample Response

```json
{
  "user": "User Data",
  "posts": "Posts Data",
  "notifications": "Notifications Data",
  "analytics": "Analytics Data"
}
```

---

## Key Concepts

- `@EnableAsync` — enables Spring's async execution support
- `@Async("taskExecutor")` — runs the method on the configured thread pool
- `CompletableFuture.allOf(...).join()` — waits for all async tasks to complete before returning
