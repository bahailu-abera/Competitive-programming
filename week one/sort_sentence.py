class Solution:
    def sortSentence(self, s: str) -> str:
        temp = s.split()
        index = []
        count = 0
        answer = str()
        for ele in temp:
            index.append(int(ele[-1]))
            temp[count] = ele[:-1]
            count += 1
        dec = {index[i]:temp[i] for i in range(len(temp))}
        
        for i in range(len(index)):
            least = i
            for k in range (i+1,len(index)):
                if index[k] < index[least]:
                    least = k
            temp = index[i]
            index[i] = index[least]
            index[least] = temp
        for ele in index:
            answer += dec[ele]
            answer += " "
        return answer[: -1]
            
       
