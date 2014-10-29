#OA Radix Theme Walkthrough:

## Ruby and Gems

Ruby is essential for modern web development; not necessarily the using the language itself but rather the myriad tools released as ruby "[gems](http://guides.rubygems.org/what-is-a-gem/)".

### Ruby for OSX and Linux:

1. Ruby is available on all modern versions of OSX. Install with your favorite package manager on Linux.
2. To interact with Ruby on OSX or Linux we'll use the built in terminal or third party terminal (like [iTerm](http://www.iterm2.com/#/section/home))].
  1. Anywhere we use "[sudo]" this indicates that sudo may be required to run the command.

### Ruby for Windows:

1. [To install for Windows take a look here.](http://rubyinstaller.org/)
2. To use ruby with Windows the built in command prompt will be used.
  1. To bring up run press `Windows key + r`
  2. Type into the run prompt `cmd` and press `enter`

### Development on this theme requires Ruby and a few gems.

We use a number of gems:

1. **sass**: The CSS preprocessor that allows elegant styling with nested selectors, functions, mixins, and much more
2. **compass**: A powerful library of prebuilt styles for SASS. Includes the invaluable auto-spriting system
3. **compass_radix**: A plugin to compass built for the base theme
4. **bootstrap-sass**: The grid framework built on compass that allows mobile-first design and structure, along with a lot more helper classes.
5. **bundler**: Allows us to set specific gem versions for a project so there are no conflicts.

### Gem Installation

Installing all of the gems above is simple:

  1. If ruby gems are not installed and you are using Linux run '[sudo] apt-get install rubygems'
  2. Install bundler: `[sudo] gem install bundler`
  3. Navigate to the theme folder and then simply run: `[sudo] bundle install`


## Workflow

During development of the theme we are utilizing Compass and SASS. Performing the above installation steps will install all the required Ruby Gems successfully write SASS.

The goal for the theme is to be as modular as possible as Open Atrium is a distribution and. SASS and Compass will aid us in this endeavor.

OA Radix is built with the intention of a theme-subtheme relationship. OA Radix, forked from Radix, uses Radix's built in Drush commands to create a new OA Radix subtheme. The OA Radix subtheme should live in the /sites/all/themes folder not in the /profile folder.

The OA Radix subtheme automatically imports all the OA Radix sass files. If you wich to overwrite any files from OA Radix simply add the file into the subtheme sass/partials folder (or a folder within) with a leading underscore i.e.'_user.scss'. It'd be advisable to copy the OA Radix file to the subtheme then edit the styles in the subtheme to retain as much style as possible.

If you wish to add a new file, be sure to add the @import to the appropriate aggregation file like _screen.scss or _node.scss. Note the order of @import is the load order.

### Using SASS

Using sass once it is installed is very simple.
1. You make all your edits in the appropriate .scss file located within the sass/ directory.
1. In your command line cd to the theme root folder.
1. Then enter one of two commands:
2. 'compass compile' to compile the sass into css once
2. 'compass watch' to compile the sass into css then continue to watch for changes. The next time you save a file in the sass/ directory compass will update the css.
3. Enter 'control + c' to stop compass watch in the command line

A note on git commits. It is possible to run into conflicts often when multiple people are writing sass. If you recieve a conflict message involving a .css file DO NOT PANIC. Simply make sure your sass files are correct then recompile. The css will then be correct and you may resovle the conflict.

### Using Compass Sprites

Using Compass sprites is extremely useful and easy

1. Add your image to the theme's assets/images/sprites folder
1. In your css rule include the sprite

Example: An image named 'left.png' would be added to a css rule

.previous{
  @include sprites-sprite("left");
}

Note: A sprites name is the name of the file sans the extension

For further information on using SASS visit:
1. http://compass-style.org/
1. http://thesassway.com/
1. http://sass-lang.com/guide
1. http://sassmeister.com/ (offers a wonderful playground to experiment)

### File Organization

With our goal to write modular SASS we will be following SMACSS guidlines. [Scalable and Modular Architecture for CSS](smacss.com) is a way to organize your CSS (and SASS) files for sane organization. Specifically we use the [Drupal-flavored version of SMCASS](https://drupal.org/node/1887918#separate-concerns). The files in sass/partials are structured in this way. "Components" are a big piece of SMACSS, so they've been broken up into their own folder.

Note: OA Radix's styles are broken up into many small sass files. This allows the sub theme to override smaller portions.

## Font Icons
Font Icons are a handy way of utilizing vector graphics. These icons, as the name suggests, are treated in the css just like a font. Since we are utilizing Bootstrap, Radix comes with Font Awesome pre-installed. Visit fontawesome.io for details. Using Font Awesome is as simple as adding a class to the html.