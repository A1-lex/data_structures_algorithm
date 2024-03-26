class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class LinkedListCycle {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
          
            return false;
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;       
            fast = fast.next.next;  

            if (slow == fast) {
                
                return true;
            }
        }

        
        return false;
    }

    public static void main(String[] args) {
        
        ListNode head1 = new ListNode(3);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(0);
        head1.next.next.next = new ListNode(-4);
        head1.next.next.next.next = head1.next;  

        ListNode head2 = new ListNode(1);
        head2.next = new ListNode(2);

        LinkedListCycle solution = new LinkedListCycle();
        System.out.println("Example 1 (has cycle): " + solution.hasCycle(head1));  
        System.out.println("Example 2 (has cycle): " + solution.hasCycle(head2));  
        System.out.println("Example 3 (no cycle): " + solution.hasCycle(new ListNode(1)));  
    }
}