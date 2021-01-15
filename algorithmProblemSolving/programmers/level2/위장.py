def solution(clothes):
    answer = 1
    tmp_list = []
    for i in range(len(clothes)):
        tmp_list.append(clothes[i][1])
    tmp_list = list(set(tmp_list))
    d = {}
    for i in range(len(tmp_list)):
        d[tmp_list[i]] = 0
    for i in range(len(clothes)):
        d[clothes[i][1]] = d[clothes[i][1]]+1
    for val in d.values():
        answer = answer*(val+1)
    return answer-1