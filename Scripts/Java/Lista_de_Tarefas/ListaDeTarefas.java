import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.sql.*;

public class ListaDeTarefas {
    private final JFrame frame;
    private final JTable table;
    private final DefaultTableModel tableModel;
    private final JTextField entradaTarefas;

    public ListaDeTarefas() {
        frame = new JFrame("Lista De Tarefas");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 400);

        tableModel = new DefaultTableModel(new Object[]{"Tarefa"}, 0);
        table = new JTable(tableModel);
        table.getColumnModel().getColumn(0).setPreferredWidth(450);
        carregarTarefa();

        JScrollPane scrollPane = new JScrollPane(table);
        frame.add(scrollPane, BorderLayout.CENTER);

        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());

        entradaTarefas = new JTextField();
        entradaTarefas.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {}

            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                    adicionarTarefa(entradaTarefas.getText());
                }
            }

            @Override
            public void keyReleased(KeyEvent e) {}
        });
        panel.add(entradaTarefas, BorderLayout.CENTER);

        JButton addButton = new JButton("Adicionar");
        addButton.addActionListener(e -> adicionarTarefa(entradaTarefas.getText()));
        panel.add(addButton, BorderLayout.EAST);

        JButton deleteButton = new JButton("Deletar");
        deleteButton.addActionListener(e -> {
            int selectedRow = table.getSelectedRow();
            if (selectedRow != -1) {
                deletarTarefa(selectedRow);
            } else {
                JOptionPane.showMessageDialog(frame, "Selecione uma tarefa para deletar", "Erro", JOptionPane.ERROR_MESSAGE);
            }
        });
        panel.add(deleteButton, BorderLayout.WEST);

        frame.add(panel, BorderLayout.SOUTH);

        frame.setVisible(true);
    }

    private void carregarTarefa() {
        try (Connection conexao = Database.connect()) {
            String sql = "SELECT * FROM tasks";
            Statement stmt = conexao.createStatement();
            ResultSet rs = stmt.executeQuery(sql);

            while (rs.next()) {
                String name = rs.getString("name");
                tableModel.addRow(new Object[]{name});
            }

            if (!rs.isBeforeFirst()) {
                System.out.println("Não há tarefas na tabela de tarefas.");
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    private void adicionarTarefa(String task) {
        if (task.isEmpty()) {
            JOptionPane.showMessageDialog(frame, "Não é possível inserir tarefa em branco", "Erro", JOptionPane.ERROR_MESSAGE);
            return;
        }

        try (Connection conexao = Database.connect()) {
            String sql = "INSERT INTO tasks(name) VALUES(?)";
            PreparedStatement pstmt = conexao.prepareStatement(sql);
            pstmt.setString(1, task);
            int rowsAffected = pstmt.executeUpdate();
            if (rowsAffected > 0) {
                System.out.println("Tarefa adicionada com sucesso.");
                atualizarTarefas();
            } else {
                System.out.println("Falha ao adicionar tarefa.");
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        entradaTarefas.setText("");
    }

    private void deletarTarefa(int rowIndex) {
        String task = (String) table.getValueAt(rowIndex, 0);
        try (Connection conexao = Database.connect()) {
            String sql = "DELETE FROM tasks WHERE name=?";
            PreparedStatement pstmt = conexao.prepareStatement(sql);
            pstmt.setString(1, task);
            int rowsAffected = pstmt.executeUpdate();
            if (rowsAffected > 0) {
                System.out.println("Tarefa deletada com sucesso.");
                atualizarTarefas();
            } else {
                System.out.println("Nenhuma tarefa encontrada para excluir.");
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    private void atualizarTarefas() {
        tableModel.setRowCount(0);
        carregarTarefa();
    }

    public static void main(String[] args) {
        Database.criarDatabase();
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new ListaDeTarefas();
            }
        });
    }
}
