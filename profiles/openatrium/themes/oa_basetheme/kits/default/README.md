#OA Basetheme Theme Walkthrough:

###**NOTES** 

*OA Basetheme uses Bower, Gulp and NodeJS/NPM.*

###Requirements
* [NodeJS](https://nodejs.org) 
* [NPM](https://www.npmjs.com/) - NPM comes as part of NodeJS

##Theming

During development of the theme we are utilizing Compass Mixins, Bootstrap,
Fontawesome and SASS. Performing the above installation steps will install all
the required Node modules successfully write SASS.

The goal for the theme is to be as modular as possible as Open Atrium is a
distribution. SASS will aid us in this endeavor.

OA Basetheme is built with the intention of a theme-subtheme relationship. Use 
OA Basetheme's built in Drush commands to create a new OA Basetheme
subtheme. The OA Basetheme subtheme should live in the /sites/all/themes folder 
not in the /profile folder.

The OA Basetheme subtheme automatically imports all the OA Basetheme sass files. If you
wish to overwrite any files from OA Basetheme simply add the file into the subtheme
sass/partials folder (or a folder within) with a leading underscore
i.e.'_user.scss'. It'd be advisable to copy the OA Basetheme file to the subtheme
then edit the styles in the subtheme to retain as much style as possible.

If you wish to add a new file, be sure to add the @import to the appropriate
aggregation file like _newpartial.scss to oa_basetheme.style.scss. Note the order of
@import is the load order.

### Using SASS

Using sass once it's installed is very simple.

* You make all your edits in the appropriate .scss file located within the scss/ directory.
* In your command line cd to the theme root folder.
* Command options:
  * ```npm run start``` will compile the sass into CSS, aggregate any JS from js/ to a 
    single file at assets/js/, and get all your font icons from bootstrap and 
    fontawesome for your assets folder. Gulp then continue to watch for changes, 
    the next time you save a file in the sass/ directory gulp will update the css.
  * ```npm run compile``` to compile the sass into css once.
  * ```npm run test``` to run eslint and sass lint.
* Enter 'control + c' to stop gulp watch in the command line

### File Organization

With our goal to write modular SASS we will be following SMACSS guidlines.
[Scalable and Modular Architecture for CSS](smacss.com) is a way to organize
your CSS (and SASS) files for sane organization. Specifically we use the
[Drupal-flavored version of
SMCASS](https://drupal.org/node/1887918#separate-concerns). The files in
sass/partials are structured in this way. "Components" are a big piece of
SMACSS, so they've been broken up into their own folder.

Note: OA Basetheme's styles are broken up into many small sass files. This allows
the sub theme to override smaller portions.

A note on git commits. It is possible to run into conflicts often when multiple
people are writing sass. If you recieve a conflict message involving a .css file
DO NOT PANIC. Simply make sure your sass files are correct then recompile. The
css will then be correct and you may resovle the conflict.

## Font Icons
Font Icons are a handy way of utilizing vector graphics. These icons, as the
name suggests, are treated in the css just like a font. Since we are utilizing
Bootstrap, OA Basetheme comes with FontAwesome and Glyphicons pre-installed. Visit
[Font Awesome Icons](http://fortawesome.github.io/Font-Awesome/icons/) and
[Bootstrap Glyphicons](http://glyphicons.bootstrapcheatsheets.com/) for details.
Using Font icons is as simple as adding a class to the html.

Note: OA Basetheme still has legacy icons in the codebase and database, the
_fontawesome_3.2.1.scss partial within the oa_basetheme theme adds the classes 
for continued support for now.

# Configuration

It's almost all done in `config.yml`. End all paths with a `/` please (i.e. 
`path/to/dir/`). The local `gulpfile.js` passes the `config` object to 
[`p2-theme-core`](https://github.com/phase2/p2-theme-core) - which can be viewed 
at `node_modules/p2-theme-core/` (most stuff in `lib/`).

### Babel JS Transpiling Config

Edit `.babelrc` for configuration of [Babel rules]
(https://babeljs.io/docs/usage/options/) that transpile JS. Default allows ES6 
to be transpiled to ES5. Learn about awesome [ES6 features]
(http://es6-features.org) here.

## More control

The `npm run` commands above basically trigger gulp without having to install a 
global dependency. For fine grained control of tasks, install gulp globally with
 `npm install --global gulp` and then run `gulp help` for a list of all available 
 tasks.

Add anything to `gulpfile.js` that you want! Also, you can copy any file from 
`node_modules/p2-theme-core/lib/` into your repo and use it as a starting point 
(may need to install packages from `p2-theme-core` too.)

Many of the features can be turned off, for example if we didn't want all the JS 
features like linting and concatenation, just toggle `enabled` under `js` in 
`config.yml`. So you'd just open `config.yml` and change this:

```yml
js:
    enabled: true
```

To this:

```yml
js:
    enabled: false
```

# Patternlab
OA Basetheme supports Patternlab (http://patternlab.io/), which can be configured in 
the config.yml file. A source and dest directory will need to be setup.

For example:

* patternlab/
  * data/
  * patternlab-css/
  * patternlab-file/
  * patterns/
  
If Patternlab is enabled in the config and the core has been installed via the 
```npm run start```, the static site will generate and be accessible via the browser.
Within the config.yml, make sure browsersync is enabled and that the path to 
Patternlab is on line 67 (#startPath: pattern-lab/public/) is uncommented.
