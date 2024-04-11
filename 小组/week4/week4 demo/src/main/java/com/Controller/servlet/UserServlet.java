package com.Controller.servlet;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.pojo.User;
import com.service.UserService;
import com.service.impl.UserServiceimpl;


import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
@WebServlet("/user/*")
public class UserServlet extends BaseServlet{
    private final UserService brandService = new UserServiceimpl();

    public  void For_Login(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        System.out.println(username + "111" + password);
        User user = brandService.login(username, password);
        ObjectMapper mapper = new ObjectMapper();
        Map<String, Object> response = new HashMap<>();
        if (user!= null) {

            response.put("success", true);
            String json = mapper.writeValueAsString(response);
            resp.setContentType("application/json");
            resp.setCharacterEncoding("UTF-8");
            resp.getWriter().write(json);
        }else{
            response.put("success", false);
            String json = mapper.writeValueAsString(response);
            resp.setContentType("application/json");
            resp.setCharacterEncoding("UTF-8");
            resp.getWriter().write(json);
        }
    }
    public void Register(HttpServletRequest req, HttpServletResponse resp) throws IOException{
        String account = req.getParameter("account");
        String registerPassword = req.getParameter("registerPassword");
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
}
