# Compiler setting
CC = g++
CXXFLAGS = -Wall -g

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj

# Include directory
INCLUDES = -I $(INCDIR)

# Source files, Object files, and Dependency files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

# Executable name
EXECUTABLE = main.exe

# Targets

$(EXECUTABLE): $(OBJS)
	$(CC) $(CXXFLAGS) $(INCLUDES) $^ -o $@ 

-include $(DEPS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CXXFLAGS) $(INCLUDES) -MMD -c $< -o $@

$(OBJDIR):
	if not exist "$(OBJDIR)" mkdir "$(OBJDIR)"

clean:
	if exist "$(OBJDIR)" rmdir /s /q "$(OBJDIR)"
	if exist "$(EXECUTABLE)" del /q "$(EXECUTABLE)"

.PHONY: clean
