package com.util;

import com.pojo.User;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class CRUD_Utills extends JDBCUtils {
    public static User authenticate(String username, String password) throws SQLException {
        String sql = "SELECT * FROM tb_user WHERE username = ? AND password = ?";
        try (Connection conn = getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {
            pstmt.setString(1, username);
            pstmt.setString(2, password);
            try (ResultSet rs = pstmt.executeQuery()) {
                if (rs.next()) {

                    return new User(rs);
                }
            }
        }
        return null;
    }

    public static boolean register(String username, String password) throws SQLException {
        String sql = "INSERT INTO tb_user VALUES (null, ?, ?)";
        try (Connection conn = getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {
            pstmt.setString(1, username);
            pstmt.setString(2, password);
            return pstmt.executeUpdate() > 0; // 返回受影响行数大于0表示插入成功
        }
    }

    public static User getUserByUsername(String username) throws SQLException {
        String sql = "SELECT * FROM tb_user WHERE username = ?";
        try (Connection conn = getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {
            pstmt.setString(1, username);
            try (ResultSet rs = pstmt.executeQuery()) {
                if (rs.next()) {
                    return new User(rs);
                }
            }
        }
        return null;
    }
}

