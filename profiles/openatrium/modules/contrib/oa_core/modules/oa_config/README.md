OPTIONAL but Recommended. Stores default settings for various contrib modules.

A Features and Features Override export of the following configuration:

- Adds Table support to WYSIWYG Filter and profile config.
- Adds AdvAgg module settings for handling IE's limit on CSS selectors
- Adds Chosen settings to display chosen drop-down on any multi-select field.
- Sets the default file scheme to PRIVATE.  This is very important for proper
  privacy control within Open Atrium.
- Skips the option for changing the file scheme when uploading files
- Configures Organic Groups to use the Space context stored within the browser session.

TODO: Probably needs to be changed to use code hooks directly or DefaultConfig
module to avoid overridden feature if the user needs to change any of these
settings.
