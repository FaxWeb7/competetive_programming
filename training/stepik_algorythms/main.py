s = input()

filter_s = []
for el in s:
    if el not in filter_s:
        filter_s.append(el)

decode_table = {}
code_symbol = "0"
for i in range(len(filter_s)):
    if i >= len(filter_s) - 2:
        decode_table[filter_s[i]] = code_symbol
        code_symbol = code_symbol[:-1] + "1"
    else:
        decode_table[filter_s[i]] = code_symbol
        code_symbol = "1" + code_symbol

result = ''
for el in s:
    result += decode_table[el]

print(len(filter_s), len(result))
for k, v in decode_table.items():
    print(k + ": " + v)
print(result)