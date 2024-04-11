package com.Controller.servlet.old;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.pojo.User;
import com.service.UserService;
import com.service.impl.UserServiceimpl;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class RegisterServlet extends HttpServlet {

    private final UserService brandService = new UserServiceimpl();


    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String account = req.getParameter("account");
        String registerPassword = req.getParameter("registerPassword");
        System.out.println("我被调用了");
        User user =brandService.check(account);
        ObjectMapper mapper = new ObjectMapper();
        Map<String, Object> response = new HashMap<>();
        if(user!=null){
            response.put("success", false);
            String json = mapper.writeValueAsString(response);
            resp.setContentType("application/json");
            resp.setCharacterEncoding("UTF-8");
            resp.getWriter().write(json);
            return;
        }
        brandService.add(account,registerPassword);
        resp.setCharacterEncoding("UTF-8");
        response.put("success", true);
        String json = mapper.writeValueAsString(response);
        resp.setContentType("application/json");
        resp.setCharacterEncoding("UTF-8");
        resp.getWriter().write(json);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doGet(req, resp);
    }
}
