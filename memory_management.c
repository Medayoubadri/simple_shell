#include "shell.h"

/**
 * free_and_nullify - Frees a pointer and sets it to NULL
 * @ptr: Pointer to the memory to free
 *
 * Description: This function frees the memory pointed to by `ptr` and
 * sets the pointer to NULL to avoid dangling pointers.
 */
void free_and_nullify(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

/**
 * free_pointer_array - Frees an array of pointers
 * @array: Array of pointers to free
 *
 * Description: This function frees each element of the array and then
 * frees the array itself. Useful for freeing tokenized command strings.
 */
void free_pointer_array(char **array)
{
	int i;

	if (!array)
		return;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
	}
	free(array);
}

/**
 * safe_realloc - Safely reallocates memory, freeing the original on failure
 * @ptr: Pointer to the memory block to reallocate
 * @new_size: The new size of the memory block
 *
 * Return: Pointer to the newly allocated memory, or NULL on failure
 *
 * Description: This function attempts to reallocate memory for `ptr` to the
 * new size specified by `new_size`. If the reallocation fails, the original
 * memory block is freed to prevent memory leaks.
 */
void *safe_realloc(void *ptr, size_t new_size)
{
	void *new_ptr = realloc(ptr, new_size);

	if (!new_ptr)
	{
		free(ptr);  /* Prevent memory leak if realloc fails */
		return (NULL);
	}

	return (new_ptr);
}

