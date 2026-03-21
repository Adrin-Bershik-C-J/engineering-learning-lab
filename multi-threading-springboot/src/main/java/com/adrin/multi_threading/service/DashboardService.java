package com.adrin.multi_threading.service;

import com.adrin.multi_threading.dto.DashboardResponse;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.concurrent.CompletableFuture;

@Service
public class DashboardService {

    @Autowired private UserService userService;
    @Autowired private PostService postService;
    @Autowired private NotificationService notificationService;
    @Autowired private AnalyticsService analyticsService;

    // ❌ WITHOUT MULTITHREADING
    public DashboardResponse getDashboardSync() {
        long start = System.currentTimeMillis();

        String user = userService.getUser();
        String posts = postService.getPosts();
        String notifications = notificationService.getNotifications();
        String analytics = analyticsService.getAnalytics();

        System.out.println("Sync Time: " + (System.currentTimeMillis() - start) + "ms");
        return new DashboardResponse(user, posts, notifications, analytics);
    }

    // ✅ WITH MULTITHREADING
    public DashboardResponse getDashboardAsync() throws Exception {
        long start = System.currentTimeMillis();

        CompletableFuture<String> user = userService.getUserAsync();
        CompletableFuture<String> posts = postService.getPostsAsync();
        CompletableFuture<String> notifications = notificationService.getNotificationsAsync();
        CompletableFuture<String> analytics = analyticsService.getAnalyticsAsync();

        CompletableFuture.allOf(user, posts, notifications, analytics).join();

        System.out.println("Async Time: " + (System.currentTimeMillis() - start) + "ms");
        return new DashboardResponse(user.get(), posts.get(), notifications.get(), analytics.get());
    }
}
