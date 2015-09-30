/** @file cmdline.h
 *  @brief The header file for the command line option parser
 *  generated by GNU Gengetopt version 2.22.6
 *  http://www.gnu.org/software/gengetopt.
 *  DO NOT modify this file, since it can be overwritten
 *  @author GNU Gengetopt by Lorenzo Bettini */

#ifndef CMDLINE_H
#define CMDLINE_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h> /* for FILE */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CMDLINE_PARSER_PACKAGE
/** @brief the program name (used for printing errors) */
#define CMDLINE_PARSER_PACKAGE "pflask"
#endif

#ifndef CMDLINE_PARSER_PACKAGE_NAME
/** @brief the complete program name (used for help and version) */
#define CMDLINE_PARSER_PACKAGE_NAME "pflask"
#endif

#ifndef CMDLINE_PARSER_VERSION
/** @brief the program version */
#define CMDLINE_PARSER_VERSION "0.3"
#endif

/** @brief Where the command line options are stored */
struct gengetopt_args_info
{
  const char *help_help; /**< @brief Print help and exit help description.  */
  const char *version_help; /**< @brief Print version and exit help description.  */
  char ** caps_arg;	/**< @brief Specify comma-separated capabilities to add ('+' prefix) or drop ('-' prefix) (default='+all').  */
  char ** caps_orig;	/**< @brief Specify comma-separated capabilities to add ('+' prefix) or drop ('-' prefix) original value given at command line.  */
  unsigned int caps_min; /**< @brief Specify comma-separated capabilities to add ('+' prefix) or drop ('-' prefix)'s minimum occurreces */
  unsigned int caps_max; /**< @brief Specify comma-separated capabilities to add ('+' prefix) or drop ('-' prefix)'s maximum occurreces */
  const char *caps_help; /**< @brief Specify comma-separated capabilities to add ('+' prefix) or drop ('-' prefix) help description.  */
  char * chroot_arg;	/**< @brief Change the root directory inside the container.  */
  char * chroot_orig;	/**< @brief Change the root directory inside the container original value given at command line.  */
  const char *chroot_help; /**< @brief Change the root directory inside the container help description.  */
  char * chdir_arg;	/**< @brief Change the current directory inside the container.  */
  char * chdir_orig;	/**< @brief Change the current directory inside the container original value given at command line.  */
  const char *chdir_help; /**< @brief Change the current directory inside the container help description.  */
  char * hostname_arg;	/**< @brief Set the container hostname.  */
  char * hostname_orig;	/**< @brief Set the container hostname original value given at command line.  */
  const char *hostname_help; /**< @brief Set the container hostname help description.  */
  char ** mount_arg;	/**< @brief Create a new mount point inside the container.  */
  char ** mount_orig;	/**< @brief Create a new mount point inside the container original value given at command line.  */
  unsigned int mount_min; /**< @brief Create a new mount point inside the container's minimum occurreces */
  unsigned int mount_max; /**< @brief Create a new mount point inside the container's maximum occurreces */
  const char *mount_help; /**< @brief Create a new mount point inside the container help description.  */
  char ** netif_arg;	/**< @brief Disconnect the container networking from the host.  */
  char ** netif_orig;	/**< @brief Disconnect the container networking from the host original value given at command line.  */
  unsigned int netif_min; /**< @brief Disconnect the container networking from the host's minimum occurreces */
  unsigned int netif_max; /**< @brief Disconnect the container networking from the host's maximum occurreces */
  const char *netif_help; /**< @brief Disconnect the container networking from the host help description.  */
  char * user_arg;	/**< @brief Run the command under the specified user (default='root').  */
  char * user_orig;	/**< @brief Run the command under the specified user original value given at command line.  */
  const char *user_help; /**< @brief Run the command under the specified user help description.  */
  char ** user_map_arg;	/**< @brief Map container users to host users.  */
  char ** user_map_orig;	/**< @brief Map container users to host users original value given at command line.  */
  unsigned int user_map_min; /**< @brief Map container users to host users's minimum occurreces */
  unsigned int user_map_max; /**< @brief Map container users to host users's maximum occurreces */
  const char *user_map_help; /**< @brief Map container users to host users help description.  */
  int ephemeral_flag;	/**< @brief Discard changes to / (default=off).  */
  const char *ephemeral_help; /**< @brief Discard changes to / help description.  */
  char ** cgroup_arg;	/**< @brief Create a new cgroup and move the container inside it.  */
  char ** cgroup_orig;	/**< @brief Create a new cgroup and move the container inside it original value given at command line.  */
  unsigned int cgroup_min; /**< @brief Create a new cgroup and move the container inside it's minimum occurreces */
  unsigned int cgroup_max; /**< @brief Create a new cgroup and move the container inside it's maximum occurreces */
  const char *cgroup_help; /**< @brief Create a new cgroup and move the container inside it help description.  */
  int detach_flag;	/**< @brief Detach from terminal (default=off).  */
  const char *detach_help; /**< @brief Detach from terminal help description.  */
  int attach_arg;	/**< @brief Attach to the specified detached process.  */
  char * attach_orig;	/**< @brief Attach to the specified detached process original value given at command line.  */
  const char *attach_help; /**< @brief Attach to the specified detached process help description.  */
  char ** setenv_arg;	/**< @brief Set additional environment variables.  */
  char ** setenv_orig;	/**< @brief Set additional environment variables original value given at command line.  */
  unsigned int setenv_min; /**< @brief Set additional environment variables's minimum occurreces */
  unsigned int setenv_max; /**< @brief Set additional environment variables's maximum occurreces */
  const char *setenv_help; /**< @brief Set additional environment variables help description.  */
  int keepenv_flag;	/**< @brief Do not clear environment (default=off).  */
  const char *keepenv_help; /**< @brief Do not clear environment help description.  */
  int no_userns_flag;	/**< @brief Disable user namespace support (default=off).  */
  const char *no_userns_help; /**< @brief Disable user namespace support help description.  */
  int no_mountns_flag;	/**< @brief Disable mount namespace support (default=off).  */
  const char *no_mountns_help; /**< @brief Disable mount namespace support help description.  */
  int no_netns_flag;	/**< @brief Disable net namespace support (default=off).  */
  const char *no_netns_help; /**< @brief Disable net namespace support help description.  */
  int no_ipcns_flag;	/**< @brief Disable IPC namespace support (default=off).  */
  const char *no_ipcns_help; /**< @brief Disable IPC namespace support help description.  */
  int no_utsns_flag;	/**< @brief Disable UTS namespace support (default=off).  */
  const char *no_utsns_help; /**< @brief Disable UTS namespace support help description.  */
  int no_pidns_flag;	/**< @brief Disable PID namespace support (default=off).  */
  const char *no_pidns_help; /**< @brief Disable PID namespace support help description.  */
  
  unsigned int help_given ;	/**< @brief Whether help was given.  */
  unsigned int version_given ;	/**< @brief Whether version was given.  */
  unsigned int caps_given ;	/**< @brief Whether caps was given.  */
  unsigned int chroot_given ;	/**< @brief Whether chroot was given.  */
  unsigned int chdir_given ;	/**< @brief Whether chdir was given.  */
  unsigned int hostname_given ;	/**< @brief Whether hostname was given.  */
  unsigned int mount_given ;	/**< @brief Whether mount was given.  */
  unsigned int netif_given ;	/**< @brief Whether netif was given.  */
  unsigned int user_given ;	/**< @brief Whether user was given.  */
  unsigned int user_map_given ;	/**< @brief Whether user-map was given.  */
  unsigned int ephemeral_given ;	/**< @brief Whether ephemeral was given.  */
  unsigned int cgroup_given ;	/**< @brief Whether cgroup was given.  */
  unsigned int detach_given ;	/**< @brief Whether detach was given.  */
  unsigned int attach_given ;	/**< @brief Whether attach was given.  */
  unsigned int setenv_given ;	/**< @brief Whether setenv was given.  */
  unsigned int keepenv_given ;	/**< @brief Whether keepenv was given.  */
  unsigned int no_userns_given ;	/**< @brief Whether no-userns was given.  */
  unsigned int no_mountns_given ;	/**< @brief Whether no-mountns was given.  */
  unsigned int no_netns_given ;	/**< @brief Whether no-netns was given.  */
  unsigned int no_ipcns_given ;	/**< @brief Whether no-ipcns was given.  */
  unsigned int no_utsns_given ;	/**< @brief Whether no-utsns was given.  */
  unsigned int no_pidns_given ;	/**< @brief Whether no-pidns was given.  */

} ;

/** @brief The additional parameters to pass to parser functions */
struct cmdline_parser_params
{
  int override; /**< @brief whether to override possibly already present options (default 0) */
  int initialize; /**< @brief whether to initialize the option structure gengetopt_args_info (default 1) */
  int check_required; /**< @brief whether to check that all required options were provided (default 1) */
  int check_ambiguity; /**< @brief whether to check for options already specified in the option structure gengetopt_args_info (default 0) */
  int print_errors; /**< @brief whether getopt_long should print an error message for a bad option (default 1) */
} ;

/** @brief the purpose string of the program */
extern const char *gengetopt_args_info_purpose;
/** @brief the usage string of the program */
extern const char *gengetopt_args_info_usage;
/** @brief the description string of the program */
extern const char *gengetopt_args_info_description;
/** @brief all the lines making the help output */
extern const char *gengetopt_args_info_help[];

/**
 * The command line parser
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser (int argc, char **argv,
  struct gengetopt_args_info *args_info);

/**
 * The command line parser (version with additional parameters - deprecated)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_parser_ext() instead
 */
int cmdline_parser2 (int argc, char **argv,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The command line parser (version with additional parameters)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_ext (int argc, char **argv,
  struct gengetopt_args_info *args_info,
  struct cmdline_parser_params *params);

/**
 * Save the contents of the option struct into an already open FILE stream.
 * @param outfile the stream where to dump options
 * @param args_info the option struct to dump
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_dump(FILE *outfile,
  struct gengetopt_args_info *args_info);

/**
 * Save the contents of the option struct into a (text) file.
 * This file can be read by the config file parser (if generated by gengetopt)
 * @param filename the file where to save
 * @param args_info the option struct to save
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_file_save(const char *filename,
  struct gengetopt_args_info *args_info);

/**
 * Print the help
 */
void cmdline_parser_print_help(void);
/**
 * Print the version
 */
void cmdline_parser_print_version(void);

/**
 * Initializes all the fields a cmdline_parser_params structure 
 * to their default values
 * @param params the structure to initialize
 */
void cmdline_parser_params_init(struct cmdline_parser_params *params);

/**
 * Allocates dynamically a cmdline_parser_params structure and initializes
 * all its fields to their default values
 * @return the created and initialized cmdline_parser_params structure
 */
struct cmdline_parser_params *cmdline_parser_params_create(void);

/**
 * Initializes the passed gengetopt_args_info structure's fields
 * (also set default values for options that have a default)
 * @param args_info the structure to initialize
 */
void cmdline_parser_init (struct gengetopt_args_info *args_info);
/**
 * Deallocates the string fields of the gengetopt_args_info structure
 * (but does not deallocate the structure itself)
 * @param args_info the structure to deallocate
 */
void cmdline_parser_free (struct gengetopt_args_info *args_info);

/**
 * Checks that all the required options were specified
 * @param args_info the structure to check
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @return
 */
int cmdline_parser_required (struct gengetopt_args_info *args_info,
  const char *prog_name);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CMDLINE_H */
