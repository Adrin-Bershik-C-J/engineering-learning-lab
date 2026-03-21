package com.adrin.multi_threading.service;

import org.springframework.scheduling.annotation.Async;
import org.springframework.stereotype.Service;

import java.util.concurrent.CompletableFuture;

@Service
public class PostService {

    public String getPosts() {
        sleep(1200);
        return "Posts Data";
    }

    @Async("taskExecutor")
    public CompletableFuture<String> getPostsAsync() {
        sleep(1200);
        System.out.println("PostService: " + Thread.currentThread().getName());
        return CompletableFuture.completedFuture("Posts Data");
    }

    private void sleep(int ms) {
        try { Thread.sleep(ms); } catch (Exception e) {}
    }
}
