# docs/source/conf.py

import os
import sys

# Add project root directory to sys.path if needed
sys.path.insert(0, os.path.abspath('../..'))

# -- Project information -----------------------------------------------------

project = 'Homework'
author = 'Els'
release = '1.0'

# -- General configuration ---------------------------------------------------

extensions = [
    'breathe',
    # 'sphinx.ext.autodoc',  # Uncomment if you use autodoc
    # 'sphinx.ext.napoleon', # Uncomment if you use Napoleon for docstrings
]

templates_path = ['_templates']
exclude_patterns = []

# -- Breathe Configuration ---------------------------------------------------

breathe_projects = {
    "Homework": os.path.abspath('../../build/docs/doxygen/xml')
}
breathe_default_project = "Homework"

# -- Options for HTML output -------------------------------------------------

html_theme = 'alabaster'  # Or any theme you prefer
html_static_path = ['_static']