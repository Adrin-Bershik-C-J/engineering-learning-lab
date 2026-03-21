package com.adrin.multi_threading.service;

import org.springframework.scheduling.annotation.Async;
import org.springframework.stereotype.Service;

import java.util.concurrent.CompletableFuture;

@Service
public class AnalyticsService {

    public String getAnalytics() {
        sleep(1500);
        return "Analytics Data";
    }

    @Async("taskExecutor")
    public CompletableFuture<String> getAnalyticsAsync() {
        sleep(1500);
        System.out.println("AnalyticsService: " + Thread.currentThread().getName());
        return CompletableFuture.completedFuture("Analytics Data");
    }

    private void sleep(int ms) {
        try { Thread.sleep(ms); } catch (Exception e) {}
    }
}
