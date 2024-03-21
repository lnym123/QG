
import java.sql.*;


//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        String sql = "SELECT * FROM tb_brand;";

        try (Connection conn = JDBCUtils.getConnection();
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(sql)) {

            while (rs.next()) {
                int id = rs.getInt("id");
                String name = rs.getString("brand_name");
                System.out.println("ID: " + id + ", BrandName: " + name);
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

}

