Open Atrium is a rich distribution of many (150+) Drupal modules. Installing 
Open Atrium may require additional resources beyond a minimal Drupal 7 
installation.

System Requirements
-------------------

In addition to the normal Drupal 7 requirements, you should ensure your PHP 
memory_limit (php.ini) is set to at least 256M and your MySQL 
max_allowed_packet (my.cnf) is at least 32M.

On a production Open Atrium site, keep in mind that the nature of 
collaboration software implies many logged-in users. Caching layers, such 
as Varnish, that are typically used to improve Drupal performance will be 
less effective because authenticated users bypass these caching layers. 
Thus, a production environment may require additional database memory and 
resources to handle larger numbers of users. Using a hosting company 
specifically tailored for Open Atrium can also help. You should not expect 
to run Open Atrium effectively on minimal (cheap) shared VM hosts.

Please also see Additional OpenAtrium requirements when installing under Aegir.

One-click installation
----------------------

Hosting companies, such as Pantheon provide an optimized infrastructure for 
Open Atrium and offer a 1-click installation process. When using Pantheon, 
skip down to the "Actual Installation" section for details.

Getting the Open Atrium files
-----------------------------

Before you can install Open Atrium, you need to get the files. There are two 
different methods for this:

** Using Releases from Drupal.org (recommended)

Official releases of Open Atrium are available on the drupal.org project page. 
Click the link for the "gz" or "zip" archive of files for the latest release. 
Older releases are also available, though not recommended. Once you have 
downloaded this file, use your systems unarchive or unzip software to extract 
all the files from the archive. These files form the "root" or top-level of 
your web site, so transfer them to the appropriate top level location of your 
web server. This will replace any existing Drupal or other web site that you 
have, so if you are overwriting existing files, be sure to make a BACKUP first!
 
** Using "git" and "drush make" for the latest -dev version (for expert Drupal devs)

(NOTE: These instructions are for *nix-based systems, such as Linux or MacOSX. 
Windows users will need to research how to use these tools on their system).

If you require the absolute latest development version of Open Atrium, you need 
to be familiar with the "git" and "drush" tools:

 * From a command line shell, run 
     "git clone --branch 7.x-2.x http://git.drupal.org/project/openatrium.git" 
   to download the latest version of Open Atrium to the "openatrium" folder 
   on your computer.

 * Move to that folder using "cd opentrium"

 * Download and build the files for Open Atrium using the script 
   "./build.sh path-to-web-server". For example, if the root of your webserver 
   is in /htdocs/drupal, then you would use "./build.sh /htdocs/drupal". 
   This will build OA2 using the latest -dev files from drupal.org. For the 
   *absolute* latest code, you can get the development code from github by 
   running "./build-dev.sh path-to-web-server" instead. This script requires 
   the "drush" command and uses "drush make" to download and build all of the 
   dependencies for Open Atrium 2. You should be using at least Drush 5.x.

 * If you receive the following error message when you attempt to build the 
   the files, you will need to install the Drupal.org Drush commands.

    "The drush command 'verify-makefile' could not be found. Run drush 
     cache-clear drush to clear the commandfile cache if you have installed 
     new extensions."

Updating your Open Atrium distribution
--------------------------------------

In the future when you wish to update to a newer version of Open Atrium, you 
have two choices, based on how you originally obtained the files as described 
in the previous section.

IMPORTANT NOTE: Before performing any site updates, it is extremely important 
to BACKUP your Drupal files and MySQL database for your site. Updating Open 
Atrium can cause irreversible changes to the database and if you decide to 
roll back you'll need this backup.

** Updating files from drupal.org (recommended)

Save a copy of your Drupal sites/ directory. This contains any local code or 
customization you might have made to your site. Now run the same procedure 
shown above to download the latest version of Open Atrium from drupal.org and 
replace your entire root web directory with the new version. Finally, replace 
the copy of the sites/ directory that you previously saved. Follow the 
instructions in the "Clearing Cache" section below to update your database and 
your site should be updates.
 
** Updating the latest -dev version (for expert Drupal devs)

If you built your site using "git" and "drush" then you can use these same 
tools to update your site. First, save a copy of your Drupal sites/ directory 
as this will be overwritten by the update process. Next, go to the "openatrium" 
folder where you initially used "git" to fetch the Open Atrium repository. Use 
"git pull" to retrieve the latest version of the distribution. Then run the 
./build.sh or ./build-dev.sh script exactly as before. Instead of pointing 
these scripts to your root web directory, you can point them to a temp 
directory in case the installation fails. The build.sh scripts delete 
everything in the target directory so building to a temp directory prevents 
your current web site from being lost if the build fails. Once the build is 
successful you can move the temporary directory in place of your web root, 
then restore the /sites directory that you previously saved.

If you just need to make a quick update of a specific open atrium module, you 
can also just go to that module directory and use "git pull origin" to pull 
in the latest changes without rebuilding the entire distribution.

Do NOT update Drupal core or any modules within Open Atrium 2 manually unless 
you are an expert Drupal developer who knows exactly what you are doing. 
Drupal Distributions such as Open Atrium are a complex collection of many 
modules, often with specific patches to make them work together. If you update 
a module manually you can easily break your Open Atrium site. The Open Atrium 
distribution is regularly updated with security patches and new features and 
is constantly evaluating new versions of modules. The advantage of using a 
distribution is to let other people handle the headache of updating modules 
and keeping them all working together.

Clearing Cache
--------------

If you are installing for the first time, ignore this section. If you are 
updating your Open Atrium distribution you'll need to run a couple of commands 
to clear the drupal cache and update your database:

drush updb
    This is the same as running the update.php script on your site and is 
    needed to run any update hooks required for the new version.
drush rr
    This is an OPTIONAL command but is sometimes needed if modules or files 
    have moved to a different directory location within Open Atrium. If you 
    get weird errors when clearing cache after an update, try this command. 
    It is a shortcut for the "registry rebuild" command which might need to 
    be installed into drush separately.
drush cc all
    This clears the Drupal database cache and is the same as clicking "Clear 
    All Caches" from the admin/config/development/performance page on your 
    site. This drush command lets you clear cache from the command line more 
    quickly.
drush fra -y (Read notes first)
    This command is required to update all of Open Atrium's features to the 
    latest version. Running it will revert and overwrite any existing 
    features, including any changes that you may have made to Open Atrium's 
    configuration. It is therefore very important to capture any customization 
    using the Features Override module before running this command. This 
    command can be run at any other time to restore Open Atrium's features to 
    their default settings (Eg: if someone has inadvertently tampered with any 
    Views or layouts within Open Atrium).

Actual Installation
-------------------

To install Open Atrium the first time, you will run the "install.php" script 
from your web browser. NOTE when using a hosting company such as Pantheon, it 
will run install.php for you. The Install script will take you through 
multiple pages of steps. There is very little difference between this process 
and a normal Drupal site installation except that it takes longer to install 
the large number of modules. 

If you are a Maintainer of Open Atrium, you should copy the gitignore.example 
file to .git/info/exclude to avoid adding extra files to the repository.

The most common problem encountered during installation is the lack of system 
resources on your web server. Be sure to follow the instructions in the System 
Requirements section shown above. If you still have trouble, try doing a plain 
Drupal 7 installation using the links in the previous section to ensure that 
your host is capable of installing Drupal itself.

