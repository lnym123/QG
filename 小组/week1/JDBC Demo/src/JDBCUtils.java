import java.sql.Connection;
import java.sql.*;

public class JDBCUtils {
    // 静态代码块
    private static final String url = "jdbc:mysql://localhost:3306/db1";
    private static final String username = "root";
    private static final String password = "1234";

    //初始化驱动
    static {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    // 获取数据库连接
    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(url, username, password);
    }

    // 关闭数据库连接
    public static void close(ResultSet set ,Statement statement,Connection conn) throws SQLException {
        set.close();
        statement.close();
        conn.close();

    }



    // 执行SQL查询
    public static ResultSet executeQuery(String sql, Object[] params, Connection conn) throws Exception {
        PreparedStatement pstmt = null;
        ResultSet rs = null;
        try {
            pstmt = conn.prepareStatement(sql);
            for (int i = 0; i < params.length; i++) {
                pstmt.setObject(i + 1, params[i]);
            }
            rs = pstmt.executeQuery();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return rs;
    }

    // 执行SQL更新（插入、删除、修改等）
    public static int executeUpdate(String sql, Object[] params, Connection conn) throws SQLException {
        PreparedStatement pstmt = null;
        int result = 0;
        try {
            pstmt = conn.prepareStatement(sql);
            for (int i = 0; i < params.length; i++) {
                pstmt.setObject(i + 1, params[i]);
            }
            result = pstmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            close(null, pstmt,conn);
        }
        return result;
    }
}
