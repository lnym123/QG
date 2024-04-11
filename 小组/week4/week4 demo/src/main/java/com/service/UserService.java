package com.service;

import com.pojo.User;

public interface UserService {

  User login(String name ,String password);
  void add(String name ,String password);

  User check(String name);
}
