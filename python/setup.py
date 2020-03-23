import setuptools
from cmake_ext import CMakeExtension, CMakeBuildExt
setuptools.setup(
    name='metric-py',
    version='0.0.2',
    ext_modules=[CMakeExtension('all')],
    cmdclass={'build_ext': CMakeBuildExt},
    author="Jura Gresko",
    author_email="juragresko@gmail.com",
    description="Metric python3 module",
    long_description="pydoc metric",
    long_description_content_type="text/markdown",
    url="https://github.com/panda-official/metric",
    packages=setuptools.find_packages(),
    python_requires='>=3.6',
    install_requires=[],
    license='MPL v2.0',
    classifiers=[
        "Development Status :: 3 - Alpha",
        "License :: OSI Approved :: Mozilla Public License 2.0 (MPL 2.0)",
        "Operating System :: OS Independent",
        "Programming Language :: Python :: 3",
    ],
    keywords=''
)
