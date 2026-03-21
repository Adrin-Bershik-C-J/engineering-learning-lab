package com.adrin.multi_threading.controller;

import com.adrin.multi_threading.dto.DashboardResponse;
import com.adrin.multi_threading.service.DashboardService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/dashboard")
public class DashboardController {

    @Autowired
    private DashboardService dashboardService;

    @GetMapping("/sync")
    public DashboardResponse getSync() {
        return dashboardService.getDashboardSync();
    }

    @GetMapping("/async")
    public DashboardResponse getAsync() throws Exception {
        return dashboardService.getDashboardAsync();
    }
}
