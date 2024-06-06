# Floyd's Cycle-Finding Algorithm:

1. Initialization: Start with two pointers, slow and fast. Both pointers begin at the head of the linked list.

2. Movement: In each step, move slow one step forward and fast two steps forward.

3. Detection:
   - If there is no cycle, fast will eventually reach the end of the list (i.e., fast or fast.next will become null).
   - If there is a cycle, slow and fast will eventually meet at some point within the cycle.

- Time Complexity: O(N)
- Space Complexity: O(1)

```C
bool hasCycle(struct node* list){
    struct node* slow = list;
    struct node* fast = list;

    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}
```

# Analogy to understand it better:

- Imagine a circular running track where runners are running laps.
  Scenario:

  - Start Line: Both slow and fast runners start at the same point on the track (head of the linked list).
  - Runners' Speeds: The slow runner jogs at a steady pace (one step at a time), while the fast runner runs at a faster pace (two steps at a time).

  Movement:

  - First Lap:
    Slow runner completes half a lap.
    Fast runner completes a full lap and starts the second lap.
  - Second Lap:
    Slow runner completes the first lap and starts the second lap.
    Fast runner completes the second lap and starts the third lap.
  - Third Lap:
    Slow runner is halfway through the second lap.
    Fast runner catches up to the slow runner in the middle of the third lap.

  At some point, the fast runner will catch up to the slow runner because the fast runner is moving faster and the track is circular. This is analogous to the slow and fast pointers meeting in a cycle within the linked list.
