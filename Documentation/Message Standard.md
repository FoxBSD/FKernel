# Message Standard to FKernel Project

The FKernel need be compile with a mix of shellscript, another languages, build system ... etc.

To maintain a minimum of readability and consistency, we have estabilished the following message standard.

## Message Structure

Each message in the system should following structure:

1. Header: Identifies the type of message and provide contextual information
2. Body: Contains the detail of the message

The format is as follow:

```
LOG: {Header}: {Body}
```

## Header Types

Headers can be several types including:

- Error: Indicates that something went wrong during execution.
- Warning: Provides a notification about something that may need atention.
- Information: Provides useful information to the user.
- Success: Indicates that operation was completed sucessfully.

## Message Formatting

Messages should be formatted in a clear concise manner. Here are some guidelines:

- Use simple and direct language
- Avoid tecnical jargon unless necessary
- Provide enough details for the user or another developers

---

## Example

To help ilustrate these guidelines, here are some examples following this standard

- **Error Message:** `Error: Failed to compile the kernel. Please check your build configuration.`

- **Warning Message:** `Warning: The current configuration may lead to slower performance.`

- **Information Message:** `Information: The kernel compiled successfully.`

- **Success Message:** `Success: The kernel module was loaded successfully.`

By adhering to this message standard, we can ensure that messages across the FKernel project are consistent, readable the provide value to the user.
