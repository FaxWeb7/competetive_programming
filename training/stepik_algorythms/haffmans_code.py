s = input()

sorted_elements = {}
for el in s:
    if el not in sorted_elements.keys():
        sorted_elements[el] = s.count(el)
sorted_elements = list(dict(sorted(sorted_elements.items(), key=lambda item: item[1], reverse=True)).keys())

decode_table = {}
code_symbol = "0"
for i in range(len(sorted_elements)):
    if i >= len(sorted_elements) - 2:
        decode_table[sorted_elements[i]] = code_symbol
        code_symbol = code_symbol[:-1] + "1"
    else:
        decode_table[sorted_elements[i]] = code_symbol
        code_symbol = "1" + code_symbol

result = ''
for el in s:
    result += decode_table[el]

print(len(sorted_elements), len(result))
for k, v in decode_table.items():
    print(k + ": " + v)
print(result)