# Greedy on Arrays

## Core Idea

Make a locally optimal decision that is guaranteed to contribute to
the globally optimal solution.

Unlike Dynamic Programming, once a greedy decision is made, it is
never revisited.

The challenge is identifying the correct invariant that allows
greedy to work.

---

## Recognition Triggers

Ask yourself:

- Can I make a decision now without regretting it later?
- Can I solve the problem in one traversal?
- Can I maintain one "best so far" value?
- Does choosing the locally best option always help?
- Can previous choices be discarded permanently?
- Am I trying to maximize reach, minimize operations, or maintain a boundary?

---

## Common Greedy Patterns

### Maximum Reach

Maintain:

Maximum Reachable Index

**Use When**
- Need to determine reachability.
- Need to expand the reachable boundary.

**Examples**
- Jump Game

---

### BFS Level Traversal

Maintain:

Current Level End

Next Level Farthest Reach

**Use When**
- Need the minimum number of jumps.
- Each jump represents one BFS level.

**Examples**
- Jump Game II

---

### Running Balance (Greedy Reset)

Maintain:

Running Balance

**Use When**
- Running balance becomes negative.
- Entire prefixes can be discarded.
- Need to determine the only valid starting point.

**Examples**
- Gas Station

---

### Best So Far

Maintain:

Minimum / Maximum Seen So Far

**Use When**
- Current answer depends only on the best previous value.

**Examples**
- Best Time to Buy and Sell Stock

---

### Take Every Profitable Move

Take every locally profitable decision.

**Use When**
- Multiple independent gains can be accumulated.

**Examples**
- Best Time to Buy and Sell Stock II

---

### Interval Greedy

Sort intervals.

Choose the interval with the earliest ending point.

**Use When**
- Need to maximize interval coverage.
- Need minimum resources for overlapping intervals.

**Examples**
- Minimum Number of Arrows to Burst Balloons
- Non-overlapping Intervals

---

## Problems Solved

| Problem | Key Idea |
|---------|----------|
| Jump Game | Maintain Maximum Reach |
| Jump Game II | BFS Level Traversal |
| Gas Station | Running Balance + Greedy Reset |

---

## Optimization Mindset

1. Identify the invariant.
2. Keep only the information necessary for future decisions.
3. Never reconsider previous choices.
4. Prove why discarded choices can never become optimal.

---

## Mental Checklist

Before coding, ask:

☐ What is the invariant?

☐ Can I solve it in one pass?

☐ Can I discard previous choices forever?

☐ Am I maintaining a boundary, balance, or best value?

☐ Can I prove my greedy choice is always safe?

---

## Keywords

Greedy

Invariant

Maximum Reach

Running Balance

Greedy Reset

BFS Level Traversal

Best So Far

Interval Greedy

One Pass

Locally Optimal Choice

Globally Optimal Solution