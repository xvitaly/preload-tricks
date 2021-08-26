/**
 * SPDX-FileCopyrightText: 2021 EasyCoding Team and contributors
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    if (getuid() != 0)
    {
        printf("%s", "This program must be run as root!\n");
        return EXIT_FAILURE;
    }
    else
    {
        printf("%s", "Root check bypassed.\n");
        return EXIT_SUCCESS;
    }
}
