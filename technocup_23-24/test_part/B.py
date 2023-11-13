m_carp = input()
b_carp = input()

if m_carp == b_carp:
    print(len(m_carp) + 1)
else:
    print(len(m_carp) - 1 if m_carp < b_carp else len(b_carp) - 1)