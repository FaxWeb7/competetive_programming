import sys
from PyQt5.QtGui import QFont, QColor
from PyQt5.QtCore import QPersistentModelIndex
from PyQt5.QtWidgets import QApplication, QMainWindow, QWidget, QTableView, QTableWidget, QPushButton, QTableWidgetItem

app = QApplication(sys.argv)

window = QMainWindow()
window.resize(1000, 500)
window.setWindowTitle('Расчет идеальной зарплаты')

# open button
def open_btn_clicked(event):
    with open('table.save', encoding='UTF-8') as f:
        lines = f.read().splitlines()
        table.setRowCount(len(lines))
        for row, line in enumerate(lines):
            for column, value in enumerate(line.split()):
                if value != 'None':
                    table.setItem(row, column, QTableWidgetItem(value))

open_btn = QPushButton('Открыть', window)
open_btn.setGeometry(0, 0, 100, 50)
open_btn.setFont(QFont('Arial', 14))
open_btn.clicked.connect(open_btn_clicked)

# save button
def save_btn_clicked(event):
    with open('table.save', 'w') as f:
        for row in range(table.rowCount()):
            try:
                line = ''
                for column in range(table.columnCount()):
                    value = table.item(row, column).text()
                    line = line + value + ' '
                f.write(line + '\n')

            except Exception as e:
                f.write('None '*table.columnCount() + '\n')

save_btn = QPushButton('Сохранить', window)
save_btn.setGeometry(100, 0, 100, 50)
save_btn.setFont(QFont('Arial', 14))
save_btn.clicked.connect(save_btn_clicked)

# users table
table = QTableWidget(5, 8, window)
table.setGeometry(0, 50, 1000, 400)
table.setHorizontalHeaderLabels(['Фамилия', 'Имя', 'Отчество',
                                'Результативность\nза месяц(%)', 'Оклад',
                                'Месячная\nзарплата\nпри результате 100%', 
                                'Размер премии при\nпревышении результата\nна 100%', 
                                'Идеальная зарплата'])

# add user button
def add_btn_clicked(event):
    table.setRowCount(table.rowCount()+1)

add_btn = QPushButton('Добавить', window)
add_btn.setGeometry(0, 450, 150, 50)
add_btn.setFont(QFont('Arial', 14))
add_btn.clicked.connect(add_btn_clicked)

# delete user btn
def delete_btn_clicked(event):
    index_list = []
    for model_index in table.selectionModel().selectedRows():
        index = QPersistentModelIndex(model_index)
        index_list.append(index)

    for index in index_list:
        table.removeRow(index.row())

delete_btn = QPushButton('Удалить', window)
delete_btn.setGeometry(150, 450, 150, 50)
delete_btn.setFont(QFont('Arial', 14))
delete_btn.clicked.connect(delete_btn_clicked)

# count salary button
def calculate_salary(effectiveness, min_salary, plan_salary, bonus, min_salary_point, max_salary_point):
    salary = 0
    if 0 <= effectiveness <= min_salary_point:
        salary = min_salary
    elif 50 < effectiveness <= 100:
        salary = plan_salary * (effectiveness / 100)
    elif 100 < effectiveness <= max_salary_point:
        salary = plan_salary + (bonus*2) * ((effectiveness / 100) - 1)
    elif effectiveness > max_salary_point:
        salary = max_salary_point / 100 * plan_salary

    return salary

def salary_btn_clicked(event):
    for index in range(table.rowCount()):
        try:
            salary = 0
            effectiveness = int(table.item(index, 3).text())
            min_salary = int(table.item(index, 4).text())
            plan_salary = int(table.item(index, 5).text())
            bonus = int(table.item(index, 6).text())
            salary = calculate_salary(effectiveness, min_salary, plan_salary, bonus, 40, 250)

            table.setItem(index, 7, QTableWidgetItem(str(salary)))
        except Exception:
            continue

salary_btn = QPushButton('Расчет идеальной зарплаты', window)
salary_btn.setGeometry(750, 450, 250, 50)
salary_btn.setFont(QFont('Arial', 16))
salary_btn.clicked.connect(salary_btn_clicked)


window.show()
sys.exit(app.exec_())