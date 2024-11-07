/*
 * @lc app=leetcode.cn id=707 lang=java
 *
 * [707] 设计链表
 */

// @lc code=start

import java.security.cert.LDAPCertStoreParameters;

class MyListNode {
    public int val;
    public MyListNode next;

    MyListNode() {
        this.next = null;
    } 
    
    MyListNode(int val) {
        this.next = null;
        this.val = val;
    }
}

class MyLinkedList {
    public MyListNode head;
    public int listLength;

    public MyLinkedList() {
        head = new MyListNode(0);
        listLength = 0;
    }
    
    public int get(int index) {
        if(index < 0 || index >= listLength) {
            return -1; // invalid
        }
        MyListNode p = head;
        for(int i = 0; i <= index; i++) {
            p = p.next;
        }
        return p.val;

    }
    
    public void addAtHead(int val) {
        MyListNode p = new MyListNode(val);
        p.next = head.next;
        head.next = p;
        listLength++;
    }
    
    public void addAtTail(int val) {
        MyListNode p = head;
        while(p.next != null) {
            p = p.next;
        }
        MyListNode q = new MyListNode(val);
        p.next = q;
        listLength++;
    }
    
    public void addAtIndex(int index, int val) {
        if(index > listLength){
            return;
        }
        if(index < 0) index = 0;
        MyListNode pre = this.head;
        for(int i = 0; i < index; i++) {
            pre =  pre.next;
        }
        MyListNode node = new MyListNode(val);
        node.next = pre.next;
        pre.next = node;
        listLength++;
        
    }

    
    public void deleteAtIndex(int index) {
        if(index < 0 || index >= listLength) {
            return;
        }
        MyListNode node = head;
        for(int i =  0; i < index; i++) {
            node = node.next;
        }
        node.next = node.next.next;
        listLength--;
        
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList()ListNode newNode = n;
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
// @lc code=end

