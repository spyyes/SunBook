# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        result = ListNode(0) #注意新建一个结构
        addon = 0
        pre = None
        while(l1 != None and l2 != None): #注意这里的条件不是next而是本身
            result = ListNode(0)
            if(pre != None):
                pre.next = result
            result.val = (l1.val + l2.val + addon)%10
            addon = (l1.val + l2.val + addon)/10
            if(pre == None):    
                root = result
            pre = result
            l1 = l1.next
            l2 = l2.next

        while(l1 != None):
            result = ListNode(0)
            pre.next = result
            result.val = (l1.val + addon)%10
            addon = (l1.val + addon)/10
            pre = result
            l1 = l1.next
        while(l2 != None):
            result = ListNode(0)
            pre.next = result
            result.val = (l2.val + addon)%10
            addon = (l2.val + addon)/10
            pre = result
            l2 = l2.next     
        if(addon != 0): #这里注意别忘了
            result = ListNode(0)
            pre.next = result
            result.val = addon
        return root
            