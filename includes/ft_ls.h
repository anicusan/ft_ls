#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <errno.h>

# include "libft.h"

# define C_RED "\e[31m"
# define C_BLUE "\e[34m"
# define C_CYAN "\e[36m"
# define C_BROWN "\e[33m"
# define C_NONE "\e[39m"
# define C_GREEN "\e[32m"
# define C_MAGENTA "\e[35m"

typedef struct		s_args
{
	char			l;
	char			r;
	char			upp_r;
	char			a;
	char			t;
	char			u;
	char			f;
	char			g;
	char			upp_g;
	char			one;
}					t_args;

typedef struct		s_dir
{
	unsigned char	d_type;
	char			*d_name;
	struct stat		dstat;
	struct s_dir	*next;
	struct s_dir	*prev;
}					t_dir;

typedef struct		s_geninfo
{
	off_t			max_size;
	nlink_t			max_nlink;
	blksize_t		max_blocks;
	size_t			max_uid;
	size_t			max_gid;
	char			*path;
	int				onepath;
	t_dir			*firstd;
	t_dir			*lastd;
	char			is_files;
	char			is_valid;
}					t_geninfo;

typedef struct		s_dto
{
	t_geninfo		*geninfo;
	t_args			*args;
	int				argc;
	char			**argv;
	int				first_path;
	int				size;
	int				size_dir;
}					t_dto;

void				ft_ls(t_args *args, t_geninfo *geninfo);
t_args				*init_args(void);
int					set_args(t_args *args, char **av, int ac);
void				generate_dir_list(DIR *dpath, t_args *args,
		t_geninfo *geninfo);
void				ls_display(t_args *args, t_geninfo *geninfo);
void				reset_geninfo(t_geninfo *geninfo);
int					ft_nbrlen(int nb);
int					ft_unsigned_nbrlen(unsigned int nb);
void				ft_unsigned_putnbr(unsigned int nb);
int					name_compare(t_dir *node1, t_dir *node2);
int					time_accessed_compare(t_dir *node1, t_dir *node2);
int					time_modified_compare(t_dir *node1, t_dir *node2);
int					no_sort(t_dir *node1, t_dir *node2);
void				print_total(t_geninfo *geninfo);
void				print_access(struct stat dstat);
void				print_links(struct stat dstat, t_geninfo *geninfo);
void				print_uid(struct stat dstat, t_geninfo *geninfo);
void				print_gid(struct stat dstat, t_geninfo *geninfo);
void				print_size(struct stat dstat, t_geninfo *geninfo);
void				print_date(time_t date);
void				print_lnkderef(char *path, t_geninfo *geninfo);
void				print_size_speshul(struct stat dstat);
void				insert_file(t_geninfo *info, t_args *args, t_dir *node);
void				get_more_info(t_dir *file, t_geninfo *geninfo);
void				usrspecial(struct stat dstat);
void				grpspecial(struct stat dstat);
void				othspecial(struct stat dstat);


#endif
