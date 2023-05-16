//你可以选择使用单链表或者双链表，设计并实现自己的链表。 
//
// 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。 
//
// 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。 
//
// 实现 MyLinkedList 类： 
//
// 
// MyLinkedList() 初始化 MyLinkedList 对象。 
// int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。 
// void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。 
// void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。 
// void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 
//index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。 
// void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。 
// 
//
// 
//
// 示例： 
//
// 
//输入
//["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", 
//"deleteAtIndex", "get"]
//[[], [1], [3], [1, 2], [1], [1], [1]]
//输出
//[null, null, null, null, 2, null, 3]
//
//解释
//MyLinkedList myLinkedList = new MyLinkedList();
//myLinkedList.addAtHead(1);
//myLinkedList.addAtTail(3);
//myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
//myLinkedList.get(1);              // 返回 2
//myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
//myLinkedList.get(1);              // 返回 3
// 
//
// 
//
// 提示： 
//
// 
// 0 <= index, val <= 1000 
// 请不要使用内置的 LinkedList 库。 
// 调用 get、addAtHead、addAtTail、addAtIndex 和 deleteAtIndex 的次数不超过 2000 。 
// 
//
// Related Topics 设计 链表 👍 833 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class MyLinkedList {

public:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int val) : val(val), next(nullptr) {}
    };

    MyLinkedList() {
        beforeHead = new ListNode(0);
        size = 0;
    }

    int get(int index) {
        //cout<<index<<endl;
        //cout<<size<<endl;
        ListNode *cur = beforeHead->next;
        if (index > size - 1 || index < 0) {
            return -1;
        } else {
            for (int i = 0; i < index; i++) {
                cur = cur->next;
            }
            return cur->val;
        }
    }

    void addAtHead(int val) {
        ListNode *head = new ListNode(val);
        head->next = beforeHead->next;
        beforeHead->next = head;
        size++;
        //cout<<"addHead "<<size<<endl;
    }

    void addAtTail(int val) {
        ListNode*cur=beforeHead;
        ListNode*tail=new ListNode(val);
        for(int i=0;i<size;i++){
            cur=cur->next;
        }
        cur->next=tail;
        size++;
        //cout<<"addAtTail "<<size<<endl;
    }

    void addAtIndex(int index, int val) {
        if(index>size){
            return;
        }
        ListNode* cur=beforeHead;
        ListNode*add=new ListNode(val);
        for(int i=0;i<index;i++){
            cur=cur->next;
        }
        add->next=cur->next;
        cur->next=add;
        size++;
        //cout<<"addAtIndex "<<size<<endl;
    }

    void deleteAtIndex(int index) {
        if(index<0||index>size-1){
            return;
        } else{
            ListNode*cur=beforeHead;
            for(int i=0;i<index;i++){
                cur=cur->next;
            }
            ListNode*tem=cur->next;
            cur->next=cur->next->next;
            delete tem;
            size--;
            //cout<<"deleteAtIndex "<<size<<endl;
        }
    }
private:
    ListNode *beforeHead;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
//leetcode submit region end(Prohibit modification and deletion)
//[6,3,1,7,4]