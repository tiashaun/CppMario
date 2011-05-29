import glob

env = Environment()

target    = 'bin/main.bin'
sources   = glob.glob('src/*.hpp') + glob.glob('src/*.cpp') + glob.glob('src/pugixml/src/*.cpp')
objects   = 'obj'
libraries = ['SDL', 'SDL_image']
flags     = '-Wall'

sources = map(lambda source: 'bin' + source[3:], sources)

env.VariantDir('bin/', 'src/')
env.Program(target = target, source = sources, LIBS = libraries, CCFLAGS = flags)
