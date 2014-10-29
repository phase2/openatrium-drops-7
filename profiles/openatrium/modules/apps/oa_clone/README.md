OPTIONAL. Adds ability to create Blueprints from Spaces, or Clone any space or
content node.

This Feature exports fields to the space_type taxonomy term for creating new
space types that clone from an existing space.

Uses the clone module to clone spaces, sub-spaces, sections, and content.  If
the space_type term has the clone option selected, creating a new space of that
type will cause the template space/subspace/section/content to be cloned to the
new space.  Otherwise, individual nodes add a Clone contextual tab button for
one-off cloning.

Adds the hook oa_clone_group_metadata($node, $original_nid) to allow other
plugins to hook into the cloning process, such as for cloning colors, banners,
etc.
