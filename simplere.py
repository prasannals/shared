def match(text, pattern, limit = -1):
    """
    Matches all or first "limit" number of occurrences of the specified pattern in the provided text
    :param text: A String of characters. This is the text in which we want to find the pattern.
    :param pattern: The pattern to look for. Expected to be a regular expression.
    :param limit: The number of occurrences of the pattern to be returned. If specified, the method returns the first
    "limit" number of occurrences of the pattern in the text(or all occurrences, whichever is lesser)
    :return: A list of matching strings and their starting and ending index values in the format
    (matching_text, start_index, end_index)
    """
    import re
    matcher = re.compile(pattern)
    matches = []
    iter = 0
    for m in matcher.finditer(text):
        entry = (m.group(), m.start(), m.end())
        matches.append(entry)
        iter += 1
        if limit != -1 and iter == limit:
            break

    return matches