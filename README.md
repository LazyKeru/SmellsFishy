<h1 id="smellsfishy" align="center">SmellsFishy</h1>
<h3 id="smellsfishy" align="center">A SAST tool, to detect hard coded secrets</h3>

<p align="center">
    <img src="./doc/img/logo.png" alt="logo">
</p>

<p align="center">
    <a href="https://github.com/LazyKeru/SmellsFishy/tags">
        <img src="https://img.shields.io/github/v/tag/LazyKeru/SmellsFishy?style=plastic" alt="release">
    </a>
    <a href="https://github.com/semantic-release/semantic-release">
        <img src="https://img.shields.io/badge/semantic--release-angular-e10079?logo=semantic-release&style=plastic" alt="semantic-release: angular">
    </a>
</p>

<p>A SAST tool, to detect hard coded secrets. Will be written in C, and use Entropy, Regex and machine learning algorithm for detection.</p>

<h2 id="how-to-use"> How to use ? </h2>

<p>To use our tool make sure your computer has <code>Make</code> or <code>Makefile</code>. You will then simply place yourself at the root of the project and enter : </p>

<pre><code>makefile main</code></pre>

<p>Then access the executable in the bin folder, and enjoy. The tool is still in beta</p>

<h2 id="workflow">Workflow</h2>

<ul>    
    <li>
        <a href="https://github.com/LazyKeru/SmellsFishy/actions/workflows/semantic_versioning.yml">
            <img src="https://img.shields.io/github/workflow/status/LazyKeru/SmellsFishy/Semantic-versionning?style=plastic&amp;label=Versionning" alt="semantic-versionning">
        </a>
    </li>
</ul>

<h2 id="commit-convention-"> Commit convention </h2>

<ul>
    <li>BREAKING CHANGE: </li>
    <li>build: Changes that affect the build system or external dependencies (example scopes: gulp, broccoli, npm)</li>
    <li>ci: Changes to our CI configuration files and scripts (examples: CircleCi, SauceLabs)</li>
    <li>docs: Documentation only changes</li>
    <li>feat: A new feature</li>
    <li>fix: A bug fix</li>
    <li>perf: A code change that improves performance</li>
    <li>refactor: A code change that neither fixes a bug nor adds a feature</li>
    <li>test: Adding missing tests or correcting existing tests</li>
</ul>
