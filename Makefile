CC = g++

FLAGS = -g -O2 -Ofast -flto -pipe -fsanitize=address

NAME = pong

SRC = main.cpp

INC = inc/pong.h

SRC_DIR = ./srcs/

OBJ_DIR = ./obj/

INC_DIR = ./inc/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

SDL_PATH = ./framework

INCLUDES = 		-I$(INC_DIR) \
				-I./frameworks/SDL2.framework/Headers \
				-I./frameworks/SDL2_image.framework/Headers \
				-I./frameworks/SDL2_ttf.framework/Headers \
				-I./frameworks/SDL2_mixer.framework/Headers \
				-F./frameworks

FRAMEWORKS = 	-F./frameworks \
				-rpath ./frameworks \
				-framework AppKit -framework OpenGL \
				-framework SDL2 -framework SDL2_image \
				-framework SDL2_mixer -framework SDL2_ttf \

all: obj_dir $(NAME)
	echo 'Compilated!'
$(NAME): $(OBJ)
	$(CC) $(FRAMEWORKS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp $(INC)
	$(CC) $(INCLUDES) -o $@ -c $<

obj_dir:
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all