def solution(phone_book):
    answer = True
    phone_book.sort()
    print(phone_book)
    if len(phone_book) == 1 :
        return answer
    else:
        for i in range(len(phone_book)-1):
            if phone_book[i] == phone_book[i+1][0:len(phone_book[i])]:
                answer = False
                return answer
    return answer