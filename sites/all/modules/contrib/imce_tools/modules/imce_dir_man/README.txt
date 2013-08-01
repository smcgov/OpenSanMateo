IMCE Directory Manager provides a function, imce_dir_man_path, that can
be used with the directory specifications in IMCE profiles along with a
management interface to control what the function returns on a user by
user basis. It is useful when users need to be confined to directories
on a user by user basis but the directory restrictions are not easily
derived from user data.

To use, create an IMCE profile and specify
'php: return imce_dir_man_path();' as the directory path the profile is
allowed to edit. On page admin/settings/imce_dir_man configure which
directories each user should be restricted to.
