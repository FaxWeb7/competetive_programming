def calculate_salary(effectiveness, min_salary, plan_salary, bonus, min_salary_point, max_salary_point):
    salary = 0
    if 0 <= effectiveness <= min_salary_point:
        salary = min_salary
    elif min_salary_point < effectiveness <= 100:
        salary = plan_salary * (effectiveness / 100)
    elif 100 < effectiveness <= max_salary_point:
        salary = plan_salary + (bonus*2) * ((effectiveness / 100) - 1)
    elif effectiveness > max_salary_point:
        salary = max_salary_point / 100 * plan_salary

    return salary




# effectiveness = int(input('Введите результативность работы сотрудника за месяц (в процентах): '))
# min_salary = int(input('Введите оклад (гарантированная часть ЗП): '))
# plan_salary = int(input('Введите плановую зарплату (зарплата сотрудника при его результативности 100%): '))
# bonus = int(input('Введите премию при привышении сотрудником результативности на 100%: '))
# min_salary_point = int(input('Введите точку отработки оклада, в процентах (в том случае, если результативность будет меньше данной отметки, сотрудник будет получать только оклад): ')) #40% default
# max_salary_point = int(input('Введите точку отработки премии, в процентах (премия за дополнительную результативность будет начисляться при результативности не более данного значения): ')) #250% default

# print(calculate_salary(effectiveness, min_salary, plan_salary, bonus,  min_salary_point, max_salary_point))