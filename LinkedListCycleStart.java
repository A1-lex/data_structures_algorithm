class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class LinkedListCycleStart {
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) {
            return null;
        }

        ListNode slow = head;
        ListNode fast = head;

        
        while (fast != null && fast.next != null) {
            slow = slow.next;       
            fast = fast.next.next;  

            if (slow == fast) {
                
                break;
            }
        }

        if (fast == null || fast.next == null) {
           
            return null;
        }

        
        slow = head;
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }

        
        return slow;
    }

    public static void main(String[] args) {
        // Example usage
        ListNode head1 = new ListNode(3);
        head1.next = new ListNode(2);
        head1.next.next = new ListNode(0);
        head1.next.next.next = new ListNode(-4);
        head1.next.next.next.next = head1.next;  // Create a cycle

        ListNode head2 = new ListNode(1);
        head2.next = new ListNode(2);

        LinkedListCycleStart solution = new LinkedListCycleStart();
        System.out.println("Example 1 (cycle begins at index): " + solution.detectCycle(head1).val);  // Output: 2
        System.out.println("Example 2 (cycle begins at index): " + solution.detectCycle(head2));  // Output: null (no cycle)
        System.out.println("Example 3 (no cycle): " + solution.detectCycle(new ListNode(1)));  // Output: null (no cycle)
    }
}