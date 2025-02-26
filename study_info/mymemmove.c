// og memmove

// Parameters: 
// *dest_str − This is a pointer for destination array where the content is to be copied. It is type-casted to a pointer of type void*.
// *src_str − The is a second pointer that denote the source of data to be copied. It is also type-casted to a pointer of type void*.
// numBytes − This parameter refer to number of bytes to be copied.

// Return Value:
// This function returns a pointer to the destination i.e *dest_str.


// my memmove:

// same as memcpy except handles cases for overlapping memory recions

// THINGS TO NOTE:
void *memmove(void *dest, const void *src, size_t n);
// Null Terminator: Copies a specified number of bytes, so it's up to the caller to ensure correct handling of null terminators for strings.
// Overlap Handling: Handles overlapping memory regions safely.
// Usage: More general-purpose; can be used for any type of data, not just strings.
// Usage: More general-purpose; can be used for any type of data, not just strings.

char *mymemmove(char *dest, char *src) {
    return dest;
}

// explanation
// The C library memchr() function is used to copy a block memory from one location to another. 
// Typically, this function state the count bytes of data from a source location to the destination.