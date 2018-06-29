I'm intrested in the exploring the kernel code because of hoping to learn some practical programming techniques from it.

1. The 'FORCE' phony target
Here I take the 'tags' target as the example.
'''Make
tags TAGS cscope: FORCE
	$(call cmd, tags)
'''

'''Make
PHONY += FORCE
FORCE:
	
# Declare the contents of the .PHONY variable as phony. We keep that
# information in a variable so we can use it in if_changed and friends.
.PHONY: $(PHONY)
'''
By this way, we can force 'tags' to be rebuilt when we specify 'FORCE' together with it.

2. Escape single quote for commands
'''Make
squote := '
# Escape single quote for use in echo statements
escsq = $(subst $(squote), '\$(squote)', $1)
'''
From the above we can learn that a backslash before $ doesn't cancel the latter's semantics.
