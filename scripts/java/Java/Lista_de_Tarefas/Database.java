import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class Database {
    private static final String DB_URL = "jdbc:sqlite:todolist.db";

    public static Connection connect() {
        Connection conexao = null;
        try {
            conexao = DriverManager.getConnection(DB_URL);
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
        return conexao;
    }

    public static void criarDatabase() {
        try (Connection conexao = connect()) {
            if (conexao != null) {
                String sql = "CREATE TABLE IF NOT EXISTS tasks ("
                        + " id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        + " name TEXT NOT NULL"
                        + ");";
                Statement stmt = conexao.createStatement();
                stmt.execute(sql);
                System.out.println("Banco de dados criado com sucesso.");
            }
        } catch (SQLException e) {
            System.out.println("Erro ao criar o banco de dados: " + e.getMessage());
        }
    }
}
