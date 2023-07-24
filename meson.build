project('ProjectRedo', 'cpp')

sources = []
subdir('src')

dependencies = [
    dependency('threads'),
    dependency('sdl2'),
    dependency('lua'),
    dependency('sol2'),
    dependency('spdlog'),
]

link_args = []

executable('ProjectRedo',
    sources: sources,
    dependencies: dependencies,
    link_args: link_args)