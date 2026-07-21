# Boyer-Moore Voting Algorithm

## Core Idea

Repeatedly cancel out votes between different elements.

An element that appears more than the required frequency
cannot be completely canceled and survives as the final candidate.

This reduces majority element problems from **O(n log n)** or
**O(n)** with extra space to **O(n)** time and **O(1)** space.

---

## Recognition Triggers

Ask yourself:

- Am I looking for an element appearing more than **n/2** or **n/3** times?
- Can different elements cancel each other out?
- Is there a guarantee on the maximum number of valid answers?
- Can I solve it without using a hash map?
- Can I maintain only a few candidates while traversing once?

---

## Common Variations

### Majority Element (> n/2)

Only one element can satisfy the condition.

Maintain:
- One candidate
- One count

**Example**
- Majority Element (LeetCode 169)

---

### Majority Element II (> n/3)

At most two elements can satisfy the condition.

Maintain:
- Two candidates
- Two counts

Perform a second pass to verify the candidates.

**Example**
- Majority Element II (LeetCode 229)

---

### Generalized Majority (> n/k)

At most **k − 1** elements can satisfy the condition.

Maintain:
- k − 1 candidates
- k − 1 counts

Verify all candidates in a final pass.

---

## Problems Solved

| Problem | Key Observation |
|---------|------------------|
| Majority Element | Only one element can appear more than n/2 times |
| Majority Element II | At most two elements can appear more than n/3 times |

---

## Optimization Mindset

1. Think in terms of vote cancellation.
2. Maintain only the possible candidates.
3. Replace candidates only when their vote count becomes zero.
4. Verify candidates if the problem does not guarantee a unique majority.

---

## Mental Checklist

Before coding, ask:

☐ Is the frequency threshold greater than n/2 or n/3?

☐ Can different elements cancel each other's votes?

☐ How many valid majority elements can exist?

☐ Do I need one candidate or multiple candidates?

☐ Is a verification pass required?

---

## Keywords

Boyer-Moore Voting Algorithm

Greedy

Vote Cancellation

Majority Element

Frequency

Candidate Selection

Constant Space

Linear Scan