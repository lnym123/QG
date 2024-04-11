package com.service.impl;
import com.util.CRUD_Utills;
import com.pojo.User;
import com.service.UserService;
import java.sql.SQLException;

//实现类
public class   UserServiceimpl implements UserService {
    @Override
    public User login(String name, String password) {
        try {
            return CRUD_Utills.authenticate(name, password);
        } catch (SQLException e) {
            throw new RuntimeException("Error authenticating user", e);
        }

    }

    public void add(String name, String password) {
        try {
            if (CRUD_Utills.register(name, password)) {
                System.out.println(name + " registered successfully");
            } else {
                System.out.println("Failed to register " + name);
            }
        } catch (SQLException e) {
            throw new RuntimeException("Error registering user", e);
        }

    }
    @Override
    public User check(String name) {
        try {
            return CRUD_Utills.getUserByUsername(name);
        } catch (SQLException e) {
            throw new RuntimeException("Error checking user", e);
        }

    }
}