package com.adrin.multi_threading.service;

import org.springframework.scheduling.annotation.Async;
import org.springframework.stereotype.Service;

import java.util.concurrent.CompletableFuture;

@Service
public class NotificationService {

    public String getNotifications() {
        sleep(800);
        return "Notifications Data";
    }

    @Async("taskExecutor")
    public CompletableFuture<String> getNotificationsAsync() {
        sleep(800);
        System.out.println("NotificationService: " + Thread.currentThread().getName());
        return CompletableFuture.completedFuture("Notifications Data");
    }

    private void sleep(int ms) {
        try { Thread.sleep(ms); } catch (Exception e) {}
    }
}
