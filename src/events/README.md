# Events folder

Here you have Discord event handlers.

Most common that you would want to look at are:

- `on-interaction.c`: handles slash commands
- `on-message-create.c`: adds XP points per message, invokes prefix commands and other shit 
- `on-prefix-command.c`: handles prefix commands (invoked by `on-message-create.c`)
