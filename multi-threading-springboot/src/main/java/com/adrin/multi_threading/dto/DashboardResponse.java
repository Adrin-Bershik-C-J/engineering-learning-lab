package com.adrin.multi_threading.dto;

public class DashboardResponse {

    private String user;
    private String posts;
    private String notifications;
    private String analytics;

    public DashboardResponse(String user, String posts, String notifications, String analytics) {
        this.user = user;
        this.posts = posts;
        this.notifications = notifications;
        this.analytics = analytics;
    }

    public String getUser() { return user; }
    public void setUser(String user) { this.user = user; }

    public String getPosts() { return posts; }
    public void setPosts(String posts) { this.posts = posts; }

    public String getNotifications() { return notifications; }
    public void setNotifications(String notifications) { this.notifications = notifications; }

    public String getAnalytics() { return analytics; }
    public void setAnalytics(String analytics) { this.analytics = analytics; }
}
