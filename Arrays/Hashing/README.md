# Hashing

## Core Idea

Don't search repeatedly.

Store useful information while traversing so future lookups become
constant time on average.

Hashing trades extra memory for faster lookups.

---

## Recognition Triggers

Ask yourself:

- Have I seen this element before?
- Do I need the frequency of elements?
- Do I need to know where an element appeared?
- Am I repeatedly searching the same data?
- Can I store information while traversing?
- Does lookup speed matter more than memory?

---

## Common Hashing Patterns

### HashSet (Existence)

Store only unique values.

**Use When**
- Need to check if an element exists.
- Need to detect duplicates.

**Examples**
- Contains Duplicate

---

### Frequency HashMap

Store:

Key → Frequency

**Use When**
- Count occurrences.
- Compare frequencies.
- Track character counts.

**Examples**
- Valid Anagram
- Ransom Note

---

### Value → Index

Store:

Value → Index

**Use When**
- Need to know where a value appeared.

**Examples**
- Two Sum

---

### Value → Last Seen Index

Store:

Value → Last Seen Index

**Use When**
- Need the nearest previous occurrence.
- Need to compare index distances.

**Examples**
- Contains Duplicate II

---

### Grouping

Store:

Computed Key → Collection of Values

**Use When**
- Multiple items belong to the same category.
- Need to group equivalent elements.

**Examples**
- Group Anagrams

---

## Problems Solved

| Problem | Key Idea |
|---------|----------|
| Valid Anagram | Character → Frequency |
| Contains Duplicate II | Value → Last Seen Index |
| Group Anagrams | Sorted String → Vector of Strings |

---

## Common STL

### unordered_set

```cpp
unordered_set<int> s;
```

Useful Operations

```cpp
s.insert(x);
s.find(x);
s.count(x);
s.erase(x);
```

---

### unordered_map

```cpp
unordered_map<int, int> mp;
```

Useful Operations

```cpp
mp[key] = value;
mp.find(key);
mp.count(key);
mp.erase(key);
```

---

## Optimization Mindset

1. Identify what information needs to be remembered.
2. Store only the minimum required information.
3. Replace repeated searches with constant-time lookups.
4. Update stored information whenever necessary.

---

## Mental Checklist

Before coding, ask:

☐ Have I seen this before?

☐ Do I need existence, frequency, or index?

☐ What should my HashMap key be?

☐ What should my HashMap value be?

☐ Can I avoid repeated searches?

---

## Keywords

HashMap

HashSet

Frequency Counting

Existence Check

Value → Index

Value → Last Seen Index

Grouping

Constant Time Lookup