package com.adrin.multi_threading.service;

import org.springframework.scheduling.annotation.Async;
import org.springframework.stereotype.Service;

import java.util.concurrent.CompletableFuture;

@Service
public class UserService {

    public String getUser() {
        sleep(1000);
        return "User Data";
    }

    @Async("taskExecutor")
    public CompletableFuture<String> getUserAsync() {
        sleep(1000);
        System.out.println("UserService: " + Thread.currentThread().getName());
        return CompletableFuture.completedFuture("User Data");
    }

    private void sleep(int ms) {
        try { Thread.sleep(ms); } catch (Exception e) {}
    }
}
