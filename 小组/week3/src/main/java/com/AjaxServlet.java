package com;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.IOException;
import com.fasterxml.jackson.databind.ObjectMapper; // 用于JSON处理

public class AjaxServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        String message = "Hello from AJAX Servlet!";

        Result result = new Result();
        result.setStatus(200);
        result.setMessage(message);

        // 将结果集转换为JSON字符串
        ObjectMapper mapper = new ObjectMapper();
        String json = mapper.writeValueAsString(result);

        // 设置响应内容类型为JSON
        resp.setContentType("application/json");
        resp.setCharacterEncoding("UTF-8");

        // 写入响应数据
        resp.getWriter().write(json);
    }

    //内部类
    static class Result {
        private int status; // 状态码
        private String message; // 消息内容

        public int getStatus() {
            return status;
        }

        public void setStatus(int status) {
            this.status = status;
        }

        public String getMessage() {
            return message;
        }

        public void setMessage(String message) {
            this.message = message;
        }
    }
}